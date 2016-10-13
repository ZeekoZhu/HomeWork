using Autofac;
using Autofac.Integration.Mvc;
using System.Web.Mvc;
using WebAuth.Services;

namespace WebAuth
{
    public class DIConfig
    {
        public static void RegisterDependencies()
        {
            var builder = new ContainerBuilder();
            builder.RegisterControllers(typeof(Global).Assembly);

            builder.RegisterType<DITestService>().InstancePerRequest();

            IContainer container = builder.Build();
            DependencyResolver.SetResolver(new AutofacDependencyResolver(container));
        }
    }
}