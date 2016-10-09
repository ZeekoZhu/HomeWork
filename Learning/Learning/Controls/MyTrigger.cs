using Windows.UI.Xaml;

namespace Learning.Controls
{
    public class MyTrigger : StateTriggerBase
    {
        public MyTrigger()
        {
            Window.Current.SizeChanged += (sender, e) =>
            {
                if (e.Size.Width >= 700 || e.Size.Height <= 450)
                {
                    SetActive(true);
                }
                else
                {
                    SetActive(false);
                }
            };
        }
    }
}
