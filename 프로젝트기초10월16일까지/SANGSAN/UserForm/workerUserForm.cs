using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
// 폴더 안에 클래스 넣어서 namespace 가 다르기 때문에 using 구문 넣어야됨.
using SANGSAN.emp;

namespace SANGSAN
{
    public partial class workerUserForm : UserControl
    {
        // database 명령어 클래스 객체 생성
        EmpCmdTable ect = new EmpCmdTable();

        public workerUserForm()
        {
            InitializeComponent();
        }
        // 조회 버튼
        private void btn_click_search(object sender, EventArgs e)
        {
            DataSet dataSet = ect.SelectEmp();
            dataGridView1.DataSource = dataSet.Tables[0];
        }
        // 등록 버튼
        private void btn_click_save(object sender, EventArgs e)
        {

            string name = tb_name.Text;
            string age = tb_age.Text;

            if(name.Length < 1)
            {
                MessageBox.Show("이름을 넣으셔야 합니다.");
                tb_name.Focus();
                return;
            }
            ect.InsertEmp(name,age);


            MessageBox.Show("저장되었습니다.");
            btn_click_search(null,null);
        }
    }
}
