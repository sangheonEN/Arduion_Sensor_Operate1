using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SANGSAN
{
    public partial class taskUserForm : UserControl
    {
        public taskUserForm()
        {
            InitializeComponent();

        }

        private void btn_Click(object sender, EventArgs e)
        {
            try
            {
                Button btn = sender as Button;
                BindingDatas.tag_num = int.Parse(btn.Tag.ToString());

                foreach (var item in this.Controls)
                {
                    if(item is Button)
                    {
                        Button con = (Button) item;
                        if(BindingDatas.tag_num == int.Parse(con.Tag.ToString()))
                        {
                            con.BackColor = Color.Red;
                        }
                        else
                        {
                            con.BackColor = Color.Blue;
                        }
                    }
                    
                }
            }
            catch (Exception exp)
            {
                Console.WriteLine(exp.StackTrace);
            }
        }
    }
}
