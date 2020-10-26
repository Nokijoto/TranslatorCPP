using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        string[] fileLine;
        public Form1()
        {
            InitializeComponent();
            
        }

        private void pp_Click(object sender, EventArgs e)
        {
            var fileContent = string.Empty;
            var filePath = string.Empty;
            
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.InitialDirectory = "c:\\";
                openFileDialog.Filter = "Aegisubs (*.ass)|*.ass "+/*|txt files (*.txt)|*.txt|*/"|All files (*.*)|*.*";
                openFileDialog.FilterIndex = 1;
                openFileDialog.RestoreDirectory = true;

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    //Get the path of specified file
                    filePath = openFileDialog.FileName;
                    var lineCount = File.ReadLines(filePath).Count();
                    //Read the contents of the file into a stream
                    var fileStream = openFileDialog.OpenFile();

                    using (StreamReader reader = new StreamReader(fileStream))
                    {
                        fileContent = reader.ReadToEnd();
                        subs.Text += fileContent;
                        //System.Console.Out.Write.
                       /* for (int i = 1; i < lineCount; i++)
                            fileLine[i] = fileContent;
                            subs.Text = fileLine[0];*/
                        // fileLine.ReadLine();
                        //return fileLine[];

                    }
                    //subs.Text = fileLine;
                   // subs.Text = fileContent;
                }
            }
        }

        private void pp_Click_2(object sender, EventArgs e)
        {
           // pp_Click_2(fileLine[]);
        }
    }
}
