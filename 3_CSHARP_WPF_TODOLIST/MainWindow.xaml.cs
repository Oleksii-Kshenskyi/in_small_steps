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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace CsharpTodolist
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void AddTaskButton_Click(object sender, RoutedEventArgs e)
        {
            var newTaskName = new CreateRenameItemDialog();
            newTaskName.Owner = this;
            if (newTaskName.ShowDialog() == true)
            {
                TodoListBox.Items.Add(new CheckBox());
                ((CheckBox)TodoListBox.Items.GetItemAt(TodoListBox.Items.Count - 1)).Content = newTaskName.NewTaskNameTextBox.Text;
            }
        }

        private void EditTaskButton_Click(object sender, RoutedEventArgs e)
        {
            if (TodoListBox.SelectedItem == null)
            {
                MessageBox.Show(this, "To edit something you have to select it from the list first!");
                return;
            }

            var newTaskName = new CreateRenameItemDialog();
            newTaskName.Owner = this;
            if (newTaskName.ShowDialog() == true)
            {
                ((CheckBox)TodoListBox.SelectedItem).Content = newTaskName.NewTaskNameTextBox.Text;
            }
        }

        private void RemoveTaskButton_Click(object sender, RoutedEventArgs e)
        {
            if (TodoListBox.SelectedItem == null)
            {
                MessageBox.Show(this, "To remove something you have to select it from the list first!");
                return;
            }

            TodoListBox.Items.Remove(TodoListBox.SelectedItem);
        }
    }
}
