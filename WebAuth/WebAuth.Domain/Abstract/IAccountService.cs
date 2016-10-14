using System.Collections.Generic;
using WebAuth.Domain.Models;

namespace WebAuth.Domain.Abstract
{
    public interface IAccountService
    {
        List<User> GetUsers();
    }
}