using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using SANGSAN;
using System.Data;
using System.Data.SqlClient;

namespace SANGSANCHART
{
    public partial class Form1 : Form
    {
        public DataSet GetTblLed()
        {
            SqlConnection conn = DataSources.GetConnection();
            SqlCommand cmd = new SqlCommand("exec proc_led_select",conn);
            DataSet ds = new DataSet();
            SqlDataAdapter sda = new SqlDataAdapter(cmd);
            sda.Fill(ds);

            DataSources.SetClose();
            return ds;
        }

        public Form1()
        {
            InitializeComponent();
            chart1.Series[0].ChartType =
               System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Pie;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            DataSet ds = GetTblLed();
            foreach (DataRow row in ds.Tables[0].Rows)
            {
                // lednum, total ,data
                Console.WriteLine("lednum = "+row[0].ToString());
                Console.WriteLine("total = " + row[1].ToString());
                Console.WriteLine("date = " + row[2].ToString());
                chart1.Series[0].Points.AddXY(row[0], row[1]);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Console.WriteLine("동작");
            chart1.Series[0].Points.Clear();
            DataSet ds = GetTblLed();
            foreach (DataRow row in ds.Tables[0].Rows)
            {
                // lednum, total ,data
                Console.WriteLine("lednum = " + row[0].ToString());
                Console.WriteLine("total = " + row[1].ToString());
                Console.WriteLine("date = " + row[2].ToString());
                chart1.Series[0].Points.AddXY(row[0], row[1]);
            }
        }
    }
}
