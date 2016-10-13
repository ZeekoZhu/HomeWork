using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
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

            return View();
        }
    }
}