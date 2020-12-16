using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data;
using System.Data.SqlClient;

namespace SANGSAN
{
    class AduinoCmdTable
    {
        public void insertCmd()
        {
            try
            {
                SqlConnection conn = DataSources.GetConnection();
                SqlCommand cmd = new SqlCommand("insert into AA values('11','22');",conn);
                cmd.ExecuteNonQuery();
            }
            catch (Exception exp)
            {
                Console.WriteLine(exp.StackTrace);
            }
            finally
            {
                DataSources.SetClose();
            }
        }

        public void insertCmd(string html)
        {
            try
            {
                SqlConnection conn = DataSources.GetConnection();
                SqlCommand cmd = new SqlCommand("insert into AA values(@aa,@bb);", conn);
                cmd.Parameters.AddWithValue("@aa", "aaaa");
                cmd.Parameters.AddWithValue("@bb", html);
                cmd.ExecuteNonQuery();
            }
            catch (Exception exp)
            {
                Console.WriteLine(exp.StackTrace);
            }
            finally
            {
                DataSources.SetClose();
            }
        }
    }
}
