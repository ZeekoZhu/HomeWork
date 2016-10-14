using System.Web.Mvc;
using WebAuth.Domain.Abstract;
using WebAuth.Domain.Services;

namespace WebAuth.Controllers
{
    public class HomeController : Controller
    {
        private readonly IAccountService _accountService;
        private DITestService Test { get; set; }


        public HomeController(DITestService test, IAccountService accountService)
        {
            _accountService = accountService;
            Test = test;
        }
        // GET: Home
        public ActionResult Index()
        {
            var model = _accountService.GetUsers();
            return View(model: model);
        }
    }
}