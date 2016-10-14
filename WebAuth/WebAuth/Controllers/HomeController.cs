using MySql.Data.MySqlClient;
using System.Data.SqlClient;
using System.Web.Mvc;
using WebAuth.Services;

namespace WebAuth.Controllers
{
    public class HomeController : Controller
    {
        public DITestService Test { get; set; }

        public HomeController(DITestService test)
        {
            Test = test;
        }
        // GET: Home
        public ActionResult Index()
        {
            string model = Test.Content;
            return View(model:model);
        }
    }
}