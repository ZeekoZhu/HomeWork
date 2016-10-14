using Dapper;
using System.Collections.Generic;
using System.Data.Common;
using System.Linq;
using WebAuth.Domain.Abstract;
using WebAuth.Domain.Models;

namespace WebAuth.Domain.Services
{
    public class AccountService : IAccountService
    {
        private readonly DbConnection _connection;

        public AccountService(DbConnection connection)
        {
            _connection = connection;
        }

        public List<User> GetUsers()
        {
            var result = _connection.Query<User>("select * from user").ToList();

            return result;
        }


    }
}