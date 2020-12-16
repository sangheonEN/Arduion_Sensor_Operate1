using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Data;
using System.Data.SqlClient;

namespace SANGSAN
{
    public partial class Form1 : Form
    {
        AduinoCmdTable AduinoCmd = new AduinoCmdTable();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //SqlConnection conn = new SqlConnection()
            SqlConnection conn = DataSources.GetConnection();

            // 주소값을 확인하여 싱글톤 패턴 확인
            //unsafe
            //{
            //    TypedReference tr1 = __makeref(conn);
            //    IntPtr ptr1 = **(IntPtr**)(&tr1);
            //    Console.WriteLine(ptr1);
            //}
           
            Console.WriteLine("conn = " + conn);
        }

        private void btnA_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void btnN_Click(object sender, EventArgs e)
        {

        }

        private void BtnNumberClick(object sender, EventArgs e)
        {
            try { 
                Button btn = sender as Button;
                if ( btn.Text.Equals("DEL") )
                {
                    tb_number.Text = tb_number.Text.Substring(0,tb_number.Text.Length-1);
                }
                else if(btn.Text.Equals("CLEAR"))
                {
                    tb_number.Text = "";
                }
                else
                {
                    tb_number.Text += btn.Text;
                }
            }catch(Exception exp)
            {
                Console.WriteLine(exp.StackTrace);
            }
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            int out_number = 0;
            int.TryParse(tb_number.Text, out out_number);
            AduinoClient.Request(BindingDatas.tag_num, out_number);
            AduinoCmd.insertCmd();
            Console.WriteLine("데이터베이스에 저장됨");
        }

        private void btnSetting_Click(object sender, EventArgs e)
        {
            settingUserForm1.BringToFront();
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            workerUserForm1.BringToFront();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            taskUserForm1.BringToFront();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            ledsUserForm1.BringToFront();
        }
    }
}
