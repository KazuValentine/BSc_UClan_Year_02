namespace CabManagementSystem.Forms
{
    partial class FormAvailableCars
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            // Create ListView control
            Lvw_ItemsList = new ListView();
            Lvw_ItemsList.Dock = DockStyle.Fill;
            Lvw_ItemsList.View = View.Details;

            // Add columns to the ListView
            Lvw_ItemsList.Columns.Add("ID", 200);
            Lvw_ItemsList.Columns.Add("Name", 450);

            SuspendLayout();

            // Add ListView to the form
            Controls.Add(Lvw_ItemsList);

            // 
            // FormItemsListView
            // 
            AutoScaleDimensions = new SizeF(15F, 31F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(879, 709);
            Controls.Add(Lbl_AboutList);
            Controls.Add(Lvw_ItemsList);
            Font = new Font("Times New Roman", 16.2F, FontStyle.Regular, GraphicsUnit.Point, 0);
            Margin = new Padding(6, 5, 6, 5);
            Name = "FormItemsListView";
            Text = "Cab Service System";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion


        private ListView Lvw_ItemsList;
        private Label Lbl_AboutList;
    }
}