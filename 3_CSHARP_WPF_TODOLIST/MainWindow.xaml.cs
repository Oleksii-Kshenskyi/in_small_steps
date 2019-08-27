using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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
        public ObservableCollection<CheckBoxContentNotifier> TheTasks { get; set; }

        public MainWindow()
        {
            InitializeComponent();
            TheTasks = new ObservableCollection<CheckBoxContentNotifier>();
            DataContext = this;
        }

        private void AddTaskButton_Click(object sender, RoutedEventArgs e)
        {
            var newTaskName = new CreateRenameItemDialog();
            newTaskName.Owner = this;
            if (newTaskName.ShowDialog() == true)
            {
                TheTasks.Add(new CheckBoxContentNotifier { CheckBoxContent = newTaskName.NewTaskNameTextBox.Text });
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
                CheckBoxContentNotifier item = ((CheckBoxContentNotifier)(TodoListBox.SelectedItem));
                item.CheckBoxContent = newTaskName.NewTaskNameTextBox.Text;
            }
        }

        private void RemoveTaskButton_Click(object sender, RoutedEventArgs e)
        {
            if (TodoListBox.SelectedItem == null)
            {
                MessageBox.Show(this, "To remove something you have to select it from the list first!");
                return;
            }

            TheTasks.Remove((CheckBoxContentNotifier)TodoListBox.SelectedItem);
        }

        private void CheckBox_Click(object sender, RoutedEventArgs e)
        {
            // TODO - Completed items are crossed out

            var item = (CheckBoxContentNotifier)((CheckBox)sender).DataContext;
            int index = TheTasks.IndexOf(item);
            if (item.IsTaskCompleted)
            {
                TheTasks.Move(index, TheTasks.Count - 1);
            }
        }
    }
}
