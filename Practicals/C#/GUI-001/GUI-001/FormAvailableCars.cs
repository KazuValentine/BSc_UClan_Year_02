using CabManagementSystem.Classes;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CabManagementSystem.Forms
{
    public partial class FormAvailableCars : Form
    {
        private void AddRow(String? id, String? name)
        {
            if (id != null && name != null)
            {
                ListViewItem item = new ListViewItem(id);
                item.SubItems.Add(name);
                Lvw_ItemsList.Items.Add(item);
            }
        }

        private void PopulateData(List<Car> availableCars)
        {
            for(int i = 0; i < availableCars.Count(); i++)
            {
                AddRow(availableCars[i].Id.ToString(), availableCars[i].Model);
            }
        }

        private List<Car> GetAvailableCars(List<Car> cars)
        {
            List<Car> availableCars = [];
            for(int i = 0;  i < cars.Count(); i++)
            {
                if (cars[i].IsAvailable)
                {
                    availableCars.Add(cars[i]);
                }
            }
            return availableCars;
        }

        public FormAvailableCars()
        {
            InitializeComponent();
            PopulateData(GetAvailableCars(DatabaseManager.LoadCars()));
        }
    }
}