using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpTodolist
{
    public class CheckBoxContentNotifier : INotifyPropertyChanged
    {
        private string _content;
        public string CheckBoxContent
        {
            get
            {
                return _content;
            }
            set
            {
                _content = value;
                NotifyPropertyChanged("CheckBoxContent");
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void NotifyPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
