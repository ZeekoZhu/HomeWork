using System.Collections.ObjectModel;
using System.ComponentModel;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

//“空白页”项模板在 http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409 上有介绍

namespace Learning
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private MainPageViewModel vm;

        public MainPage()
        {
            this.InitializeComponent();
            vm = new MainPageViewModel { Students = new ObservableCollection<Student>() };
            for (int i = 0; i < 20; i++)
            {
                vm.Students.Add(new Student() { Age = i });
            }
            DataContext = vm;

        }

        private void ButtonBase_OnClick(object sender, RoutedEventArgs e)
        {
            if (vm.SelectedStudent != null)
            {
                vm.Students.Remove(vm.SelectedStudent);
            }
        }
    }

    public class MainPageViewModel
    {
        public ObservableCollection<Student> Students { get; set; }
        public Student SelectedStudent { get; set; }
    }

    public class Student : INotifyPropertyChanged
    {
        private int _age;

        public int Age
        {
            get { return _age; }
            set
            {
                _age = value;
                PropertyChangedEventHandler handler = PropertyChanged;
                handler?.Invoke(this, new PropertyChangedEventArgs(nameof(Age)));
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}
