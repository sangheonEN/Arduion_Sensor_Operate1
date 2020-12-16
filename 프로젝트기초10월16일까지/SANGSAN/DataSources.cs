using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// 데이터 베이스 연결시에 필요한 네임스페이스
using System.Data;
using System.Data.SqlClient;

namespace SANGSAN
{
    // DB 연결 가져오기 객체
    // DB 연결 자원 반환
    public class DataSources
    {
        private static string strconn = "Data Source=192.168.0.19;Initial Catalog=SANGSAN;Persist Security Info=True;User ID=sa;Password=1234";
        private static SqlConnection conn = null;

        public static SqlConnection GetConnection()
        {
            if(conn == null) { 
                conn = new SqlConnection(strconn);
            }
            conn.Open();
            Console.WriteLine("연결 성공");
            return conn;
        }

        public static void SetClose()
        {
            if (conn != null) { 
                Console.WriteLine("연결 끊기 성공");
                conn.Close();
            }
        }
    }
}
