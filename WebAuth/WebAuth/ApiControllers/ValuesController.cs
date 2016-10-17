using System.Collections.Generic;
using System.Web.Http;
using WebAuth.Domain.Abstract;

namespace WebAuth.ApiControllers
{
    public class ValuesController : ApiController
    {
        private readonly IAccountService _accountService;

        public ValuesController(IAccountService accountService)
        {
            _accountService = accountService;
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

        [HttpPost]
        public void Post([FromBody]string username, string password)
        {
            _accountService.Login(username, password);
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
}