namespace Demp
{
    using WPControls;
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.wButton1 = new WButton();
            this.SuspendLayout();
            // 
            // wButton1
            // 
            this.wButton1.BackColor = System.Drawing.SystemColors.ControlDark;
            this.wButton1.Location = new System.Drawing.Point(563, 90);
            this.wButton1.Name = "wButton1";
            this.wButton1.Size = new System.Drawing.Size(148, 69);
            this.wButton1.TabIndex = 0;
            this.wButton1.Text = "wButton1";
            this.wButton1.UseVisualStyleBackColor = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(941, 520);
            this.Controls.Add(this.wButton1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private WButton wButton1;
    }
}

