//
// provides a convenient way to have a log file
//
using System;
using System.IO;
using System.Windows.Forms;
using SendFileTo;
//  send email
//http://stackoverflow.com/questions/1195111/c-sharp-mailto-with-attachment

namespace GLEED2D
{

    public class Logger
    {
        private const long MaxLogFileSize = 3 * 1024 * 1024;// 3MB

        private static Logger instance;
        public static Logger Instance
        {
            get
            {
                if (instance == null) instance = new Logger();
                return instance;
            }
        }

        string logfilename = System.Windows.Forms.Application.StartupPath + "\\log.txt";
        StreamWriter sw;

        public Logger()
        {
            bool continueWork = true;

            float fileSize = 0;
            if (File.Exists(logfilename))
            {
                FileInfo info = new System.IO.FileInfo(logfilename);
                if (info != null)
                    fileSize = info.Length;
            }

            if (fileSize >= MaxLogFileSize)
                continueWork = false;

            sw = new StreamWriter(logfilename, continueWork);
            sw.WriteLine(box("Log File created.\r\n\r\n"));
            sw.Close();
        }


        public void log(string message)
        {
            sw = new StreamWriter(logfilename, true);
            sw.WriteLine(box(message));
            sw.Close();            
        }

        string box(string message)
        {
            return DateTime.Now + "." + DateTime.Now.Millisecond.ToString("000") + " - " + message;
        }

        private String getPublicSignature()
        {
            return "\r\nEditor Version: " + Editor.Instance.Version
                    + "\r\nOperating System: " + Environment.OSVersion.ToString() 
                    //+ (IntPtr.Size == 8 ? " x64" : " x86")
                    + "\r\n";
                    
        }

        public void emailToDevelopers()
        {
            try
            {
                MAPI m = new MAPI();
                m.AddAttachment(logfilename);
                m.AddRecipientTo("vasamajka@gmail.com");
                String subject = "[LevelEditor] Please review my error log";
                String body = "";

                body += getPublicSignature();

                m.SendMailPopup(subject, body);
            }
            catch (Exception)
            {
                MessageBox.Show("Hmmm... Something bad happened...", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        public void emailFeatureRequest()
        {
            try
            {
                MAPI m = new MAPI();                
                m.AddRecipientTo("vasamajka@gmail.com");
                String subject = "[LevelEditor] New feature request";
                String body = "\r\r\n";

                body += getPublicSignature();

                m.SendMailPopup(subject, body);
            }
            catch (Exception)
            {
                MessageBox.Show("Hmmm... Something bad happened...", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

    }

}