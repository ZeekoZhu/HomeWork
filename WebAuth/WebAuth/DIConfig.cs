using Autofac;
using Autofac.Integration.Mvc;
using MySql.Data.MySqlClient;
using System.Configuration;
using System.Data.Common;
using System.Web.Mvc;
using WebAuth.Domain.Abstract;
using WebAuth.Domain.Services;

namespace WebAuth
{
    public class DIConfig
    {
        public static void RegisterDependencies()
        {
            var builder = new ContainerBuilder();
            builder.RegisterControllers(typeof(Global).Assembly);

            builder.RegisterType<DITestService>().InstancePerRequest();

            builder.Register((c) =>
            {
                DbConnection conn = new MySqlConnection(ConfigurationManager.ConnectionStrings["MySqlConnection"].ToString());
                return conn;
            }).InstancePerRequest();

            builder.RegisterType<AccountService>().As<IAccountService>().InstancePerRequest();

            IContainer container = builder.Build();
            DependencyResolver.SetResolver(new AutofacDependencyResolver(container));
        }
    }
}