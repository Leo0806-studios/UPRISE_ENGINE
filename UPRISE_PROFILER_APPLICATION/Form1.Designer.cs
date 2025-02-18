namespace UPRISE_PROFILER_APPLICATION
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            openFileDialog1 = new OpenFileDialog();
            treeViewProfiler = new TreeView();
            btnLoad = new Button();
            ElemnttDetails = new RichTextBox();
            statusStrip1 = new StatusStrip();
            toolStripProgressBar1 = new ToolStripProgressBar();
            toolStripStatusLabel1 = new ToolStripStatusLabel();
            LoadProfLog = new Button();
            Scale_MS = new Button();
            Scale_US = new Button();
            Scale_NS = new Button();
            statusStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // openFileDialog1
            // 
            openFileDialog1.FileName = "openFileDialog1";
            openFileDialog1.FileOk += openFileDialog1_FileOk;
            // 
            // treeViewProfiler
            // 
            treeViewProfiler.DrawMode = TreeViewDrawMode.OwnerDrawAll;
            treeViewProfiler.FullRowSelect = true;
            treeViewProfiler.Location = new Point(12, 41);
            treeViewProfiler.Name = "treeViewProfiler";
            treeViewProfiler.Size = new Size(1384, 795);
            treeViewProfiler.TabIndex = 10;
            treeViewProfiler.DrawNode += treeViewProfiler_DrawNode;
            treeViewProfiler.AfterSelect += treeViewProfiler_AfterSelect;
            // 
            // btnLoad
            // 
            btnLoad.Location = new Point(12, 12);
            btnLoad.Name = "btnLoad";
            btnLoad.Size = new Size(75, 23);
            btnLoad.TabIndex = 11;
            btnLoad.Text = "LoadEvents";
            btnLoad.UseVisualStyleBackColor = true;
            btnLoad.Click += btnLoad_Click;
            // 
            // ElemnttDetails
            // 
            ElemnttDetails.Location = new Point(1402, 41);
            ElemnttDetails.Name = "ElemnttDetails";
            ElemnttDetails.Size = new Size(490, 628);
            ElemnttDetails.TabIndex = 12;
            ElemnttDetails.Text = "";
            ElemnttDetails.TextChanged += ElemnttDetails_TextChanged;
            // 
            // statusStrip1
            // 
            statusStrip1.Items.AddRange(new ToolStripItem[] { toolStripProgressBar1, toolStripStatusLabel1 });
            statusStrip1.Location = new Point(0, 1019);
            statusStrip1.Name = "statusStrip1";
            statusStrip1.Size = new Size(1904, 22);
            statusStrip1.TabIndex = 13;
            statusStrip1.Text = "statusStrip1";
            // 
            // toolStripProgressBar1
            // 
            toolStripProgressBar1.Name = "toolStripProgressBar1";
            toolStripProgressBar1.Size = new Size(100, 16);
            // 
            // toolStripStatusLabel1
            // 
            toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            toolStripStatusLabel1.Size = new Size(118, 17);
            toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // LoadProfLog
            // 
            LoadProfLog.Location = new Point(104, 12);
            LoadProfLog.Name = "LoadProfLog";
            LoadProfLog.Size = new Size(75, 23);
            LoadProfLog.TabIndex = 14;
            LoadProfLog.Text = "LoadProfLog";
            LoadProfLog.UseVisualStyleBackColor = true;
            LoadProfLog.Click += LoadProfLog_Click;
            // 
            // Scale_MS
            // 
            Scale_MS.Location = new Point(319, 12);
            Scale_MS.Name = "Scale_MS";
            Scale_MS.Size = new Size(75, 23);
            Scale_MS.TabIndex = 15;
            Scale_MS.Text = "Scale_MS";
            Scale_MS.UseVisualStyleBackColor = true;
            Scale_MS.Click += Scale_MS_Click;
            // 
            // Scale_US
            // 
            Scale_US.Location = new Point(400, 12);
            Scale_US.Name = "Scale_US";
            Scale_US.Size = new Size(75, 23);
            Scale_US.TabIndex = 16;
            Scale_US.Text = "Scale_US";
            Scale_US.UseVisualStyleBackColor = true;
            Scale_US.Click += Scale_US_Click;
            // 
            // Scale_NS
            // 
            Scale_NS.Location = new Point(481, 12);
            Scale_NS.Name = "Scale_NS";
            Scale_NS.Size = new Size(75, 23);
            Scale_NS.TabIndex = 17;
            Scale_NS.Text = "Scale_NS";
            Scale_NS.UseVisualStyleBackColor = true;
            Scale_NS.Click += Scale_NS_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1904, 1041);
            Controls.Add(Scale_NS);
            Controls.Add(Scale_US);
            Controls.Add(Scale_MS);
            Controls.Add(LoadProfLog);
            Controls.Add(statusStrip1);
            Controls.Add(ElemnttDetails);
            Controls.Add(btnLoad);
            Controls.Add(treeViewProfiler);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            statusStrip1.ResumeLayout(false);
            statusStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private OpenFileDialog openFileDialog1;
        private TreeView treeViewProfiler;
        private Button btnLoad;
        private RichTextBox ElemnttDetails;
        private StatusStrip statusStrip1;
        private ToolStripProgressBar toolStripProgressBar1;
        private ToolStripStatusLabel toolStripStatusLabel1;
        private Button LoadProfLog;
        private Button Scale_MS;
        private Button Scale_US;
        private Button Scale_NS;
    }
}
