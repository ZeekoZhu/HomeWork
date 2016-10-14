using Autofac;
using Autofac.Integration.Mvc;
using MySql.Data.MySqlClient;
using System.Data.Common;
using System.Web.Mvc;
using WebAuth.Services;
using Dapper;
using System.Data.SqlClient;
using System.Configuration;

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
                DbConnection conn = new MySqlConnection(ConfigurationManager.ConnectionStrings);
                return conn;
            });

            IContainer container = builder.Build();
            DependencyResolver.SetResolver(new AutofacDependencyResolver(container));
        }
    }
}