using Dapper;
using System;
using System.Data.Common;
using System.Globalization;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using WebAuth.Domain.Abstract;
using WebAuth.Domain.Models;

namespace WebAuth.Domain.Services
{
    public class AccountService : IAccountService
    {
        private readonly DbConnection _connection;

        private readonly string _table = "user";

        private PasswordEncryptor PasswordEncryptor { get; set; } = ComputeMD5;

        public AccountService(DbConnection connection)
        {
            _connection = connection;
        }

        public LoginResult Login(string userName, string password)
        {
            password = PasswordEncryptor(userName, password);
            var result = _connection.Query<User>($"select * from {_table} where UserName=@{nameof(userName)} and Password=@{nameof(password)}",
                new { userName, password })
                .ToList()
                .FirstOrDefault();
            if (result == null)
            {
                return new LoginResult() { AuthToken = "", RefreshToken = "", Success = false };
            }
            else
            {
                result.AuthToken = ComputeMD5("", DateTime.Now.ToString(CultureInfo.CurrentCulture));
                result.AuthExpire = result.AuthExpire ??
                                    Convert.ToInt64((DateTime.Now + TimeSpan.FromDays(7)).Subtract(new DateTime(1970, 1, 1)).TotalMilliseconds);
                result.RefreshToken = result.RefreshToken ?? ComputeMD5("", DateTime.Now.ToString(CultureInfo.CurrentCulture) + userName);
                result.RefreshExpire = result.RefreshExpire ?? Convert.ToInt64((DateTime.Now + TimeSpan.FromDays(30)).Subtract(new DateTime(1970, 1, 1))
                                        .TotalMilliseconds);

                string updateSql =
                    $@"UPDATE user 
                    SET AuthExpire=@{nameof(result.AuthExpire)},
                    AuthToken=@{nameof(result.AuthToken)},
                    RefreshToken=@{nameof(result.RefreshToken)},
                    RefreshExpire=@{nameof(result.RefreshExpire)} WHERE UserId=@{nameof(result.UserId)}";
                _connection.Execute(updateSql, new { result.AuthExpire, result.AuthToken, result.RefreshToken, result.RefreshExpire, result.UserId });
            }

            return new LoginResult() { AuthToken = result.AuthToken, RefreshToken = result.RefreshToken, Success = true };
        }

        /// <summary>
        /// 计算MD5，作为默认的密码加密设置
        /// </summary>
        /// <param name="str">The string.</param>
        /// <returns></returns>
        private static string ComputeMD5(string usr, string str)
        {
            MD5 m = new MD5CryptoServiceProvider();
            byte[] s = m.ComputeHash(Encoding.UTF8.GetBytes(str));
            string res = BitConverter.ToString(s);
            res = res.ToLower();
            res = res.Replace("-", "");
            return res;
        }
    }

    internal delegate string PasswordEncryptor(string userName, string pwd);

    /// <summary>
    /// 用户登录结果
    /// </summary>
    public class LoginResult
    {
        public string AuthToken { get; set; }
        public string RefreshToken { get; set; }
        public bool Success { get; set; }
    }

    public class RegisterResult
    {
        public string AuthToken { get; set; }
        public string RefreshToken { get; set; }
        public bool Success { get; set; }
    }
}