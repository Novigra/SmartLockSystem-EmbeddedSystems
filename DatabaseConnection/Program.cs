using FireSharp;
using FireSharp.Interfaces;
using System;
using System.IO.Ports;
using ServerConnection;

namespace DatabaseConnection
{
    public class Program
    {
        static void Main(string[] args)
        {
            var Port = new SerialPort("COM3", 9600);
            //Port.Close();
            Port.Open();

            Connect.Init("28wUT47veCn1EWoJKnp34WxJcd1cqwuZNAYFezxy", "https://note-4010a-default-rtdb.firebaseio.com/");
            Client client = new Client();

            string time = DateTime.Now.ToString();

            while(true)
            {
                if(Port.BytesToRead > 0)
                {
                    client.SetData(Port.ReadLine());
                    client.AddDataToServer(time);

                    Console.WriteLine($"[{time}] :: {Port.ReadLine()}");
                }
            }

        }
    }
}