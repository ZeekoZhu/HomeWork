using WebAuth.Domain.Services;

namespace WebAuth.Domain.Abstract
{
    public interface IAccountService
    {
        LoginResult Login(string userName, string password);
    }
}