using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhyExperiment
{
    class Phy
    {
        public static double ComputeA(List<double> datas)
        {
            double avg = datas.Sum() / datas.Count;
            double res = Math.Sqrt(
                datas.Sum(
                    (d) => Math.Pow((d - avg), 2)
                    ) / (datas.Count * (datas.Count - 1)));
            return res;
        }

        public static double ComputeB(double error) => erroe/Math.
    }
}
