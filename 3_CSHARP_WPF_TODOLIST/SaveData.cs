using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpTodolist
{
    class SaveData
    {
        public ObservableCollection<CheckBoxContentNotifier> TheTasks { get; set; }
        public int LastUncheckedItemIndex { get; set; }
    }
}
