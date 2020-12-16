using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SANGSAN.emp
{
    class EmpCmdTable
    {
        // 같은 프로젝트에서는 public 처럼 접근을 하는 역할
        internal void InsertEmp(string name, string age)
        {
            SqlConnection conn = DataSources.GetConnection();
            SqlCommand cmd = new SqlCommand("exec proc_emp_insert @name,@age", conn);
            cmd.Parameters.AddWithValue("@name",name);
            cmd.Parameters.AddWithValue("@age", age);
            cmd.ExecuteNonQuery();

            DataSources.SetClose();
        }

        internal DataSet SelectEmp()
        {
            SqlConnection conn = DataSources.GetConnection();
            SqlCommand cmd = new SqlCommand("exec proc_emp_select",conn);
            SqlDataAdapter sda = new SqlDataAdapter(cmd);
            DataSet dataSet = new DataSet();

            sda.Fill(dataSet);

            DataSources.SetClose();

            return dataSet;
        }
    }
}
