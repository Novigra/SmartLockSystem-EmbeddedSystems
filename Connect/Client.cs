using FireSharp.Interfaces;
using System.Xml.Linq;

namespace ServerConnection
{
    public class Client : Connect
    {
        private string Data;

        public Client() { }

        public Client(string data)
        {
            Data = data;
        }

        public void AddDataToServer(string time)
        {
            string FinalData = $"{time} :: {Data}";
            FClient.Set("Logs/", FinalData);
        }

        public void SetData(string data)
        {
            Data = data;
        }

        public string GetData()
        {
            return Data;
        }
    }
}
