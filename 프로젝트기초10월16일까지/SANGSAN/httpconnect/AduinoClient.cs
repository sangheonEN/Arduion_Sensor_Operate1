using SANGSAN.cmd;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

namespace SANGSAN
{
    class AduinoClient
    {
        static readonly HttpClient client = new HttpClient();

        public static async Task Request(int pin, int num)
        {
            try
            {
                String url = $@"{BindingDatas.http_url}/{pin}/{num}";
                Console.WriteLine($"url =  {url}");
                HttpResponseMessage response = await client.GetAsync(url);
                response.EnsureSuccessStatusCode();
                string responseBody = await response.Content.ReadAsStringAsync();

                Console.WriteLine(responseBody);

                //AduinoCmdTable act = new AduinoCmdTable();
                //act.insertCmd(responseBody);
                LedCmdTable lct = new LedCmdTable();
                lct.insertTBL_LED(pin, num);
            }
            catch (HttpRequestException e)
            {
                Console.WriteLine("\nException Caught!");
                Console.WriteLine("Message :{0} ", e.Message);
            }
        }
    }
}
