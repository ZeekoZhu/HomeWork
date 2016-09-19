using HtmlAgilityPack;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

namespace Hdu_Now_Core
{
    public class WebWorker
    {
        protected HtmlWeb HtmlWeb;
        private string Url;
        protected CookieContainer cookies;

        public WebWorker(string url)
        {
            Url = url;
            cookies = new CookieContainer();
        }

        public HtmlDocument Document;

        public async Task Load()
        {
            Document = await HtmlWeb.LoadFromWebAsync(Url);
        }

        public async Task SendLoginRequest(string usr, string pwd)
        {
            HttpRequest request = WebRequest.Create(Url) as HttpWebRequest;
            request.Method = "GET";
            request.CookieContainer = cookies;
        }

    }
}
