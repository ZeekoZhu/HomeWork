using System.Collections.Generic;
using System.Web.Http;
using WebAuth.Domain.Abstract;

namespace WebAuth.ApiControllers
{
    public class AccountController : ApiController
    {
        private readonly IAccountService _accoutService;

        public AccountController(IAccountService accoutService)
        {
            _accoutService = accoutService;
        }
        // GET api/<controller>
        public IEnumerable<string> Get()
        {
            return new string[] { "value1", "value2" };
        }

        // GET api/<controller>/5
        public string Get(int id)
        {
            return "value";
        }

        // POST api/<controller>
        [HttpPost]
        public bool Post([FromBody]LoginInfo loginInfo)
        {
            return _accoutService.Login(loginInfo.username, loginInfo.password).Success;
        }

        // PUT api/<controller>/5
        public void Put(int id, [FromBody]string value)
        {
        }

        // DELETE api/<controller>/5
        public void Delete(int id)
        {
        }
    }

    public class LoginInfo
    {
        public string username { get; set; }
        public string password { get; set; }
    }
}