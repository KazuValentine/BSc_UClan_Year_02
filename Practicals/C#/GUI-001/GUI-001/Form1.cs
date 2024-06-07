namespace GUI_001
{
    public partial class Form1 : Form
    {
        private List<String> myTasks = new List<String>();
        public Form1()
        {
            InitializeComponent();
        }

        private void RefreshData()
        {
            TasksListBox.DataSource = null;
            TasksListBox.DataSource = myTasks;
        }

        private void AddTaskBtn_Click(object sender, EventArgs e)
        {
            myTasks.Add(TaskTxt.Text);
            TaskTxt.Text = String.Empty;
            RefreshData();
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            RefreshData();
        }

        private void TasksListBox_DoubleClick(object sender, EventArgs e)
        {
            if(myTasks.Count < 1)
                return;
            myTasks.RemoveAt(TasksListBox.SelectedIndex);
            RefreshData();
        }
    }
}
