namespace GUI_001
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            TaskTxt = new TextBox();
            AddTaskBtn = new Button();
            TasksListBox = new ListBox();
            SuspendLayout();
            // 
            // TaskTxt
            // 
            TaskTxt.Font = new Font("Times New Roman", 16.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            TaskTxt.Location = new Point(30, 27);
            TaskTxt.Margin = new Padding(6, 5, 6, 5);
            TaskTxt.Name = "TaskTxt";
            TaskTxt.Size = new Size(450, 39);
            TaskTxt.TabIndex = 0;
            // 
            // AddTaskBtn
            // 
            AddTaskBtn.BackColor = SystemColors.MenuHighlight;
            AddTaskBtn.Font = new Font("Times New Roman", 16.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            AddTaskBtn.Location = new Point(519, 27);
            AddTaskBtn.Name = "AddTaskBtn";
            AddTaskBtn.Size = new Size(141, 39);
            AddTaskBtn.TabIndex = 1;
            AddTaskBtn.Text = "Add";
            AddTaskBtn.UseVisualStyleBackColor = false;
            AddTaskBtn.Click += AddTaskBtn_Click;
            // 
            // TasksListBox
            // 
            TasksListBox.FormattingEnabled = true;
            TasksListBox.ItemHeight = 31;
            TasksListBox.Location = new Point(30, 85);
            TasksListBox.Name = "TasksListBox";
            TasksListBox.Size = new Size(612, 376);
            TasksListBox.TabIndex = 2;
            TasksListBox.DoubleClick += TasksListBox_DoubleClick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(16F, 31F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(702, 499);
            Controls.Add(TasksListBox);
            Controls.Add(AddTaskBtn);
            Controls.Add(TaskTxt);
            Font = new Font("Times New Roman", 16.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            Margin = new Padding(6, 5, 6, 5);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox TaskTxt;
        private Button AddTaskBtn;
        private ListBox TasksListBox;
    }
}
