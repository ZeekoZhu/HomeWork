using Autofac;
using Autofac.Integration.Mvc;
using Autofac.Integration.WebApi;
using MySql.Data.MySqlClient;
using System.Configuration;
using System.Data.Common;
using System.Reflection;
using System.Web.Http;
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

            RegisterServices(builder);

            IContainer container = builder.Build();
            DependencyResolver.SetResolver(new AutofacDependencyResolver(container));
        }

        public static void RegisterServices(ContainerBuilder builder)
        {
            builder.RegisterType<DITestService>().InstancePerRequest();

            builder.Register((c) =>
            {
                DbConnection conn = new MySqlConnection(ConfigurationManager.ConnectionStrings["MySqlConnection"].ToString());
                return conn;
            }).InstancePerRequest();

            builder.RegisterType<AccountService>().As<IAccountService>().InstancePerRequest();
        }

        public static void RegisterWebApiDependencies()
        {
            var builder = new ContainerBuilder();
            var config = GlobalConfiguration.Configuration;
            builder.RegisterApiControllers(Assembly.GetExecutingAssembly());

            RegisterServices(builder);

            var container = builder.Build();
            config.DependencyResolver = new AutofacWebApiDependencyResolver(container);
        }
    }
}