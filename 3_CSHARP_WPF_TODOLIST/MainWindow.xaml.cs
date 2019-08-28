using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
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
using Newtonsoft.Json;

namespace CsharpTodolist
{
    public partial class MainWindow : Window
    {
        public ObservableCollection<CheckBoxContentNotifier> TheTasks { get; set; }

        public const string PathToSaveFile = "test.json";

        public static int LastUncheckedItemIndex = -1;

        private void SerializeTasks()
        {
            if (TheTasks != null)
            {
                string json = JsonConvert.SerializeObject(TheTasks, Formatting.Indented);
                File.WriteAllText(PathToSaveFile, json);
            }
        }

        private void DeserializeTasks()
        {
            try
            {
                string file = File.ReadAllText(PathToSaveFile);
                TheTasks = JsonConvert.DeserializeObject<ObservableCollection<CheckBoxContentNotifier>>(file);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Couldn't get the current collection from the save file.\n" +
                                $"Exception: { ex.Message },\n" +
                                $"Trace: { ex.StackTrace }.");
            }
        }

        public MainWindow()
        {
            InitializeComponent();
            DeserializeTasks();
            DataContext = this;
        }

        private void AddTaskButton_Click(object sender, RoutedEventArgs e)
        {
            var newTaskName = new CreateRenameItemDialog();
            newTaskName.Owner = this;
            if (newTaskName.ShowDialog() == true)
            {
                LastUncheckedItemIndex++;
                TheTasks.Insert(LastUncheckedItemIndex, new CheckBoxContentNotifier { CheckBoxContent = newTaskName.NewTaskNameTextBox.Text });
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
            var item = (CheckBoxContentNotifier)TodoListBox.SelectedItem;

            if (!item.IsTaskCompleted)
            {
                LastUncheckedItemIndex--;
            }

            TheTasks.Remove(item);
        }

        private void CheckBox_Click(object sender, RoutedEventArgs e)
        {
            var item = (CheckBoxContentNotifier)((CheckBox)sender).DataContext;
            int index = TheTasks.IndexOf(item);
            if (item.IsTaskCompleted)
            {
                TheTasks.Move(index, TheTasks.Count - 1);
                LastUncheckedItemIndex--;
            }
            else
            {
                LastUncheckedItemIndex++;
                TheTasks.Move(index, LastUncheckedItemIndex);
            }
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            SerializeTasks();
        }
    }
}
