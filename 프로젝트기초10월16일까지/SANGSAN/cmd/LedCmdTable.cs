using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;

namespace SANGSAN.cmd
{
    class LedCmdTable
    {
        public void insertTBL_LED(int pin,int cnt)
        {
            SqlConnection connection = DataSources.GetConnection();
            SqlCommand sqlCommand = new SqlCommand("exec proc_led_insert @led_num,@led_count", connection);
            sqlCommand.Parameters.AddWithValue("@led_num", pin);
            sqlCommand.Parameters.AddWithValue("@led_count", cnt);
            sqlCommand.ExecuteNonQuery();
            DataSources.SetClose();
        }
    }
}
