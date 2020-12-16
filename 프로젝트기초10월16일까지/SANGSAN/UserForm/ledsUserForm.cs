using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace SANGSAN
{
    public partial class ledsUserForm : UserControl
    {
        public ledsUserForm()
        {
            InitializeComponent();

        }

        private void btn_Click(object sender, EventArgs e)
        {
            //Console.WriteLine("버튼 되나");
            PictureBox pb = sender as PictureBox;
            foreach (var item in this.Controls) {
                if (item is Label) {
                    Label label = (Label)item;
                    //Console.WriteLine("label.Tag " + label.Tag);
                    //Console.WriteLine("label.Text " + label.Text);
                    //Console.WriteLine("pb.Tag "+pb.Tag);
                    if (pb.Tag == label.Tag)
                    {
                        //Console.WriteLine("tag = "+ label.Tag);
                        label.BackColor = Color.Red;
                        BindingDatas.tag_num = int.Parse(label.Text);
                    }
                    else
                    {
                        label.BackColor = Color.Transparent;
                    }
                }
            }
            //pb.Image = global::SANGSAN.Properties.Resources.led_on_trans;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 아두이노 요청 하는 것
            AduinoClient.Request(BindingDatas.tag_num,int.Parse(textBox1.Text));
            // 화면에서 깜박이는 것도 만들어야된다...
            CompleteOnOff(int.Parse(textBox1.Text));

            // db 저장도 해야됨...

        }

        public async Task CompleteOnOff(int cnt)
        {
            PictureBox pb = await OnOffImage(cnt);
            Console.WriteLine($"{cnt}회 횟수 완료");
        }

        public async Task<PictureBox> OnOffImage(int cnt)
        {
            PictureBox temp = null;
            foreach (var item in this.Controls)
            {
                if( item is PictureBox)
                {
                    temp = (PictureBox)item;
                    if(temp.Tag.ToString() == BindingDatas.tag_num.ToString())
                    {
                        while(cnt > 0) { 
                            temp.Image = global::SANGSAN.Properties.Resources.led_on_trans;
                            temp.Update();
                            Thread.Sleep(500);
                            temp.Image = global::SANGSAN.Properties.Resources.led_off_trans;
                            temp.Update();
                            Thread.Sleep(500);
                            cnt--;
                        }
                    }
                }
            }
            return temp;
        }
    }
}
