using System.Collections.Generic;

namespace WebAuth.Domain.Models
{
    public class User
    {
        public int UserId { get; set; }
        public string UserName { get; set; }
        public string Password { get; set; }
        public string AuthToken { get; set; }
        public long? AuthExpire { get; set; }
        public string RefreshToken { get; set; }
        public long? RefreshExpire { get; set; }
        //public FuckClass Fuck { get; set; }

        public List<FuckClass> Fucked { get; set; }
        public FuckClass Unfacked { get; set; }
    }
}
