namespace WindowsFormsApp3
{
    partial class Form1
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            this.pp = new System.Windows.Forms.Button();
            this.subs = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // pp
            // 
            this.pp.Location = new System.Drawing.Point(86, 45);
            this.pp.Name = "pp";
            this.pp.Size = new System.Drawing.Size(75, 23);
            this.pp.TabIndex = 0;
            this.pp.Text = "Otwórz";
            this.pp.UseVisualStyleBackColor = true;
            this.pp.Click += new System.EventHandler(this.pp_Click);
            // 
            // subs
            // 
            this.subs.Location = new System.Drawing.Point(34, 90);
            this.subs.Multiline = true;
            this.subs.Name = "subs";
            this.subs.ReadOnly = true;
            this.subs.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.subs.Size = new System.Drawing.Size(688, 327);
            this.subs.TabIndex = 1;
            this.subs.Text = "TEST";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(232, 45);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 2;
            this.button1.Text = "Załaduj";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.subs);
            this.Controls.Add(this.pp);
            this.Name = "Form1";
            this.Text = "Form1";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button pp;
        private System.Windows.Forms.TextBox subs;
        private System.Windows.Forms.Button button1;
    }
}

