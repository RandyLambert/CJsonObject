#include <string>
#include <iostream>
#include "../CJsonObject.hpp"
using namespace std;
int main()
{
    int iValue;
    double fTimeout;
    std::string strValue;
    neb::CJsonObject oJson1;
    oJson1.AddEmptySubObject("test");
    oJson1["test"].Add("uid",1);
    oJson1["test"].Add("passWord","dadsadkashd");
    cout<<oJson1.ToFormattedString()<<endl;
    while(oJson1["test"].GetKey(strValue))
    {
        cout<<strValue<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
     oJson1.AddEmptySubArray("insert");
     oJson1["insert"].Add("1");
     oJson1["insert"].Add("dsd1");
     oJson1["insert"].Add("xxxx");
     oJson1["insert"].Add("1");
     oJson1["insert"].Add("1");
     for(int i = 0;i < oJson1["insert"].GetArraySize();i++)
     {
         cout<<oJson1["insert"](i)<<endl;
        /* oJson1["insert"].Get(i,strValue); */
        /* cout<<strValue<<endl; */
     }
     
     neb::CJsonObject oJson2;
     oJson2.Add("insertObj","user");
     oJson2.AddEmptySubArray("data");
     neb::CJsonObject oJson3;
     oJson3.Add("11","233");
     oJson3.Add("hh","dasd");
     oJson3.Add("1das1","ss233");
     oJson3.Add("1dsad1","dad233");
     oJson3.Add("11dsa","dsada233");
     oJson2["data"].Add(oJson3);
     oJson2["data"].Add(oJson3);
     oJson2.AddEmptySubObject("ojson3");
     oJson2.Replace("oJson3",oJson3);
     cout<<oJson2.ToFormattedString()<<endl;
     string tmp,tmp1;
     for(int i = 0;i < oJson2["data"].GetArraySize();i++)
         while(oJson2["data"][i].GetKey(tmp))
         {
             oJson2["data"].Get(tmp,tmp1);
             cout<<tmp<<" "<<tmp1<<endl;
         }

     neb::CJsonObject obj1;
     obj1.AddEmptySubArray("what");
     obj1["what"].Add("*");
     obj1.AddEmptySubArray("op");
     obj1["op"].Add("=");
     obj1["op"].Add("=");
     obj1.Add("tableName","user");
     obj1.AddEmptySubObject("data");
     obj1["data"].Add("userName","管理员");
     obj1["data"].Add("passWord","123456");
     cout<<obj1.ToFormattedString()<<endl;

    
    getchar();

    neb::CJsonObject oJson("{\"refresh_interval\":60,"
                        "\"test_float\":[18.0, 10.0, 5.0],"
                        "\"timeout\":12.5,"
                        "\"dynamic_loading\":["
                            "{"
                                "\"so_path\":\"plugins/User.so\", \"load\":false, \"version\":1,"
                                "\"cmd\":["
                                     "{\"cmd\":2001, \"class\":\"neb::CmdUserLogin\"},"
                                     "{\"cmd\":2003, \"class\":\"neb::CmdUserLogout\"}"
                                "],"
                                "\"module\":["
                                     "{\"path\":\"im/user/login\", \"class\":\"neb::ModuleLogin\"},"
                                     "{\"path\":\"im/user/logout\", \"class\":\"neb::ModuleLogout\"}"
                                "]"
                             "},"
                             "{"
                             "\"so_path\":\"plugins/ChatMsg.so\", \"load\":false, \"version\":1,"
                                 "\"cmd\":["
                                      "{\"cmd\":2001, \"class\":\"neb::CmdChat\"}"
                                 "],"
                             "\"module\":[]"
                             "}"
                        "]"
                    "}");
     std::cout << oJson.ToString() << std::endl;
     std::cout << "-------------------------------------------------------------------" << std::endl;
     std::cout << oJson["dynamic_loading"][0]["cmd"][1]("class") << std::endl;
     std::cout << oJson["dynamic_loading"][0]["cmd"][1].ToString() << std::endl;
     oJson["dynamic_loading"][0]["cmd"][0].Get("cmd", iValue);
     std::cout << "iValue = " << iValue << std::endl;
     oJson["dynamic_loading"][0]["cmd"][0].Replace("cmd", -2001);
     oJson["dynamic_loading"][0]["cmd"][0].Get("cmd", iValue);
     std::cout << "iValue = " << iValue << std::endl;
     oJson.Get("timeout", fTimeout);
     std::cout << "fTimeout = " << fTimeout << std::endl;
     oJson["dynamic_loading"][0]["module"][0].Get("path", strValue);
     std::cout << "strValue = " << strValue << std::endl;
     std::cout << "-------------------------------------------------------------------" << std::endl;
     oJson.AddEmptySubObject("depend");
     oJson["depend"].Add("nebula", "https://github.com/Bwar/Nebula");
     oJson["depend"].AddEmptySubArray("bootstrap");
     oJson["depend"]["bootstrap"].Add("BEACON");
     oJson["depend"]["bootstrap"].Add("LOGIC");
     oJson["depend"]["bootstrap"].Add("LOGGER");
     oJson["depend"]["bootstrap"].Add("INTERFACE");
     oJson["depend"]["bootstrap"].Add("ACCESS");
     std::cout << oJson.ToString() << std::endl;
     std::cout << "-------------------------------------------------------------------" << std::endl;
     std::cout << oJson.ToFormattedString() << std::endl;

     std::cout << "-------------------------------------------------------------------" << std::endl;
     neb::CJsonObject oCopyJson = oJson;
     if (oCopyJson == oJson)
     {
         std::cout << "json equal" << std::endl;
     }
     oCopyJson["depend"]["bootstrap"].Delete(1);
     oCopyJson["depend"].Replace("nebula", "https://github.com/Bwar/CJsonObject");
     std::cout << oCopyJson.ToString() << std::endl;
     std::cout << "-------------------------key traverse------------------------------" << std::endl;
     std::string strTraversing;
     while(oJson["dynamic_loading"][0].GetKey(strTraversing))
     {
         std::cout << "traversing:  " << strTraversing << std::endl;
     }
     std::cout << "---------------add a new key, then key traverse---------------------" << std::endl;
     oJson["dynamic_loading"][0].Add("new_key", "new_value");
     while(oJson["dynamic_loading"][0].GetKey(strTraversing))
     {
         std::cout << "traversing:  " << strTraversing << std::endl;
     }

     std::cout << oJson["test_float"].GetArraySize() << std::endl;
     float fTestValue = 0.0;
     for (int i = 0; i < oJson["test_float"].GetArraySize(); ++i)
     {
         oJson["test_float"].Get(i, fTestValue);
         std::cout << fTestValue << std::endl;
     }
     oJson.AddNull("null_value");
     oJson.Add("value",12);
     std::cout << oJson.IsNull("test_float") << "\t" << oJson.IsNull("null_value") << std::endl;
     oJson["test_float"].AddNull();
     oJson["test_float"].Add(1.1);
     std::cout << oJson.ToString() << std::endl;
     std::cout << oJson.ToFormattedString() << std::endl;

}

