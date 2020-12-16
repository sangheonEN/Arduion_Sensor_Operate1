namespace SANGSAN
{
    partial class taskUserForm
    {
        /// <summary> 
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region 구성 요소 디자이너에서 생성한 코드

        /// <summary> 
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("굴림", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(54, 66);
            this.label1.Margin = new System.Windows.Forms.Padding(8, 0, 8, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(212, 48);
            this.label1.TabIndex = 2;
            this.label1.Text = "업무화면";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(254, 153);
            this.button1.Margin = new System.Windows.Forms.Padding(8);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(170, 80);
            this.button1.TabIndex = 3;
            this.button1.Tag = "10";
            this.button1.Text = "10번LED";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.btn_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(62, 153);
            this.button2.Margin = new System.Windows.Forms.Padding(8);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(170, 80);
            this.button2.TabIndex = 4;
            this.button2.Tag = "11";
            this.button2.Text = "11번LED";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.btn_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(440, 153);
            this.button3.Margin = new System.Windows.Forms.Padding(8);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(170, 80);
            this.button3.TabIndex = 5;
            this.button3.Tag = "9";
            this.button3.Text = "9번LED";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.btn_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(626, 153);
            this.button4.Margin = new System.Windows.Forms.Padding(8);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(170, 80);
            this.button4.TabIndex = 6;
            this.button4.Tag = "6";
            this.button4.Text = "6번LED";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.btn_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(812, 153);
            this.button5.Margin = new System.Windows.Forms.Padding(8);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(170, 80);
            this.button5.TabIndex = 7;
            this.button5.Tag = "5";
            this.button5.Text = "5번LED";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.btn_Click);
            // 
            // taskUserForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(19F, 33F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Pink;
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Font = new System.Drawing.Font("다음_Regular", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Margin = new System.Windows.Forms.Padding(8);
            this.Name = "taskUserForm";
            this.Size = new System.Drawing.Size(1264, 590);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
    }
}
