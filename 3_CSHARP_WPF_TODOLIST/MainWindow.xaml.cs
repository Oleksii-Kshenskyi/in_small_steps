using System;
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

        private void TodoListBox_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            var newTaskName = new CreateRenameItemDialog();
            newTaskName.Owner = this;
            if (newTaskName.ShowDialog() == true)
            {
                TodoListBox.Items.Add(new CheckBox());
                ((CheckBox)TodoListBox.Items.GetItemAt(TodoListBox.Items.Count - 1)).Content = newTaskName.NewTaskNameTextBox.Text;
            }
        }
    }
}
