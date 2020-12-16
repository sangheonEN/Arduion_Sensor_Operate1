using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AduinoClient
{
    

    public partial class Form1 : Form
    {
        public static int AAA = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // async 비동기
            // sync 동기

            Request(10);
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("이것도 실행됨");
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            Request(11);
        }

        static readonly HttpClient client = new HttpClient();

        static async Task Request(int pin)
        {
            // Call asynchronous network methods in a try/catch block to handle exceptions.
            try
            {
                String url = $@"http://192.168.0.30/{pin}";
                HttpResponseMessage response = await client.GetAsync(url);
                response.EnsureSuccessStatusCode();
                string responseBody = await response.Content.ReadAsStringAsync();
                // Above three lines can be replaced with new helper method below
                // string responseBody = await client.GetStringAsync(uri);

                Console.WriteLine(responseBody);
            }
            catch (HttpRequestException e)
            {
                Console.WriteLine("\nException Caught!");
                Console.WriteLine("Message :{0} ", e.Message);
            }
        }

        
    }
}
