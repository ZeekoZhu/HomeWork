using System;

namespace WebAuth.Helpers
{
    public class FrontEndHelper
    {
        /// <summary>
        /// 转换基本类型为 js 类型
        /// </summary>
        /// <param name="typeInfo">The type information.</param>
        /// <returns></returns>
        public static string ConvertBaseType(Type typeInfo)
        {
            string result = "object";
            if (typeInfo == typeof(string))
            {
                result = "string";
            }
            else if (typeInfo == typeof(bool))
            {
                result = "boolean";
            }
            else
            {
                result = "number";
            }
            return result;
        }



    }
}