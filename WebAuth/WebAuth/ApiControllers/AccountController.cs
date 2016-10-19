using System.Web.Http;
using WebAuth.Domain.Abstract;

namespace WebAuth.ApiControllers
{
    /// <summary>
    /// 用户账户控制器
    /// </summary>
    public class AccountController : ApiController
    {
        private readonly IAccountService _accoutService;

        /// <summary>
        /// Initializes a new instance of the <see cref="AccountController"/> class.
        /// </summary>
        /// <param name="accoutService">The accout service.</param>
        public AccountController(IAccountService accoutService)
        {
            _accoutService = accoutService;
        }


        /// <summary>
        /// 登录
        /// </summary>
        /// <param name="loginInfo">登录信息</param>
        /// <returns></returns>
        [HttpPost]
        public bool Login([FromBody]LoginInfo loginInfo)
        {
            return _accoutService.Login(loginInfo.username, loginInfo.password).Success;
        }
    }

    public class LoginInfo
    {
        public string username { get; set; }
        public string password { get; set; }
    }
}