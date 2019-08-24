﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace CsharpTodolist
{
    /// <summary>
    /// Interaction logic for CreateRenameItemDialog.xaml
    /// </summary>
    public partial class CreateRenameItemDialog : Window
    {
        public CreateRenameItemDialog()
        {
            InitializeComponent();

            WindowStartupLocation = WindowStartupLocation.CenterOwner;
        }

        private void ConfirmTaskNameButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = true;
        }
    }
}
