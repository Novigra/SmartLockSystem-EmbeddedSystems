using FireSharp;
using FireSharp.Config;
using FireSharp.Interfaces;

namespace ServerConnection
{
    public class Connect
    {
        private static string AuthSecret;
        private static string BasePath;
        protected static IFirebaseClient FClient;

        public static void Init(string authSecret, string basePath)
        {
            AuthSecret = authSecret;
            BasePath = basePath;

            IFirebaseConfig FirebaseConfig = new FirebaseConfig()
            {
                AuthSecret = AuthSecret,
                BasePath = BasePath
            };

            IFirebaseClient FirebaseClient = new FirebaseClient(FirebaseConfig);

            FClient = FirebaseClient;
        }

        public static string GetAuthSecret()
        {
            return AuthSecret;
        }

        public static string GetBasePath()
        {
            return BasePath;
        }
    }
}