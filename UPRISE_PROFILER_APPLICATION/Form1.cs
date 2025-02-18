// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
namespace UPRISE_PROFILER_APPLICATION
{
    public partial class Form1 : Form
    {
        enum Scale_Enum
        {
            NS,
            US,
            MS
        } 
        static Scale_Enum Currnet_Sacele=Scale_Enum.MS;
        private float zoomfactor = 1.0f;
        private float zoomstep = 0.1f;
        private float zoommax = 4.0f;
        private float zoommin = 0.5f;
        private ulong start;
        private int depth = 0;
        public Form1()
        {
            InitializeComponent();


            treeViewProfiler.AfterSelect += treeViewProfiler_AfterSelect;
        }

        private void MAinThreaddDrawer_MouseWheel(object? sender, MouseEventArgs e)
        {
            //if (e.Delta > 0)
            //{
            //    zoomfactor += zoomstep;
            //    if (zoomfactor > zoommax)
            //    {
            //        zoomfactor = zoommax;
            //    }
            //}
            //else
            //{
            //    zoomfactor -= zoomstep;
            //    if (zoomfactor < zoommin)
            //    {
            //        zoomfactor = zoommin;
            //    }
            //}
            //MAinThreaddDrawer.Invalidate();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        static int conter = 0;
        protected override void OnPaint(PaintEventArgs e)
        {

            base.OnPaint(e);
            Graphics g = e.Graphics;
            g.Clear(Color.White);
            conter++;
            double yPosition = 10;  // Start at the top
            double barHeight = 30;  // Height of each event bar



        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void openFileDialog1_FileOk(object sender, System.ComponentModel.CancelEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {


        }

        private void MAinThreaddDrawer_Paint(object sender, PaintEventArgs e)
        {
            base.OnPaint(e);
            Graphics g = e.Graphics;
            g.Clear(Color.Gray);
            g.ScaleTransform(zoomfactor, zoomfactor);
            long xpos = 0;
            ulong ypos = 0;
            long barWidth = 100;
            long barHeight = 50;
            List<RectangleF> list = new List<RectangleF>();
            foreach (var profilingEvent in Globals._profilingTimerEvents_Main)
            {
                if (profilingEvent.Details.Function == " main")
                {
                    start = profilingEvent.Details.Timestamp;
                }
            }
            foreach (var profilingEvent in Globals._profilingTimerEvents_Main)
            {

                double timeinns = 0;
                //if (profilingEvent.Details.Duration.Unit == "ns")
                //{
                    timeinns = profilingEvent.Details.Duration.Value;
                //}
                //else if (profilingEvent.Details.Duration.Unit == "us")
                //{
                //    timeinns = profilingEvent.Details.Duration.Value * 1000;
                //}
                //else if (profilingEvent.Details.Duration.Unit == "ms")
                //{
                //    timeinns = profilingEvent.Details.Duration.Value * 1000 * 1000;
                //}
                //else if (profilingEvent.Details.Duration.Unit == "s")
                //{
                //    timeinns = profilingEvent.Details.Duration.Value * 1000 * 1000 * 1000;
                //}
                long timeOffset = (long)(profilingEvent.Details.Timestamp - start) / 1000 / 1000;
                barWidth = (long)timeinns / 1000 / 1000;
                int thisDepthe = profilingEvent.Details.Stacktrace.Count() - 6;
                if (thisDepthe == depth)
                {
                    xpos = timeOffset + barWidth;
                }
                depth = profilingEvent.Details.Stacktrace.Count() - 7;
                Color c = Color.FromArgb(255, (profilingEvent.Details.Stacktrace.Count() * 50) % 255, (profilingEvent.Details.Stacktrace.Count() * 34) % 255);
                string text = profilingEvent.Details.Duration.Value.ToString() + " ns" ;

            }
        }

        private void MAinThreaddDrawer_Scroll(object sender, ScrollEventArgs e)
        {
        }

        private void ZoominMain_Click(object sender, EventArgs e)
        {
            zoomfactor += zoomstep;
            if (zoomfactor > zoommax)
            {
                zoomfactor = zoommax;
            }

        }

        private void ZoomoutMain_Click(object sender, EventArgs e)
        {
            zoomfactor -= zoomstep;
            if (zoomfactor < zoommin)
            {
                zoomfactor = zoommin;
            }

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {
            base.OnPaint(e);
            Graphics g = e.Graphics;
            g.Clear(Color.Gray);
            g.ScaleTransform(zoomfactor, zoomfactor);
            long xpos = 0;
            ulong ypos = 0;
            long barWidth = 100;
            long barHeight = 50;
            List<RectangleF> list = new List<RectangleF>();
            foreach (var profilingEvent in Globals._profilingTimerEvents_Threads[27872])
            {
                if (profilingEvent.Details.Function == " main")
                {
                    start = profilingEvent.Details.Timestamp;
                }
            }
            start = Globals._profilingTimerEvents_Threads[27872].First().Details.Timestamp;
            foreach (var profilingEvent in Globals._profilingTimerEvents_Threads[27872])
            {

                double timeinns = 0;

                    timeinns = profilingEvent.Details.Duration.Value;

           
                long timeOffset = (long)(profilingEvent.Details.Timestamp - start) / 1000 / 1000;
                barWidth = (long)timeinns / 1000 / 1000;
                int thisDepthe = profilingEvent.Details.Stacktrace.Count() - 6;
                if (thisDepthe == depth)
                {
                    xpos = timeOffset + barWidth;
                }
                depth = profilingEvent.Details.Stacktrace.Count() - 7;
                Color c = Color.FromArgb(255, (profilingEvent.Details.Stacktrace.Count() * 50) % 255, (profilingEvent.Details.Stacktrace.Count() * 34) % 255);
                string text = profilingEvent.Details.Duration.Value.ToString() + " ns";

            }
        }
        private TreeNode ConvertToTreeNode(FunctionStructure function)
        {
            TimerTreeNode node = new TimerTreeNode(function.ProfilingEvent);
            // TreeNode node = new TreeNode($"{function.name} ({function.ProfilingEvent?.Details.Duration.Value} {function.ProfilingEvent?.Details.Duration.Unit})");

            if (function.Children != null)
            {
                foreach (var child in function.Children)
                {
                    node.Nodes.Add(ConvertToTreeNode(child));
                }
            }
            return node;
        }
        private void btnLoad_Click(object sender, EventArgs e)
        {
            Globals._functionStructure_main = FunctionStructure.WalkStructure(Globals._profilingTimerEvents_Main);

            treeViewProfiler.Nodes.Clear();
            if (Globals._functionStructure_main != null)
            {
                TreeNode rootNode = ConvertToTreeNode(Globals._functionStructure_main);
                treeViewProfiler.Nodes.Add(rootNode);
                treeViewProfiler.ExpandAll();
            }
        }

        private void treeViewProfiler_AfterSelect(object sender, TreeViewEventArgs e)
        {

            TimerTreeNode local = e.Node as TimerTreeNode;
            double childTime = local.GetAlltimeOfChildren();
            int childCount = local.Nodes.Count; // Direct child count
   
                    childTime = childTime;


            string function = "Function: " + local.ProfilingEvent.Details.Function.ToString();
            string duration = "";
            string ctime = "";
            switch (Currnet_Sacele)
            {
                case Scale_Enum.NS:
                    duration = "Duration: " + local.ProfilingEvent.Details.Duration.Value.ToString() + " ns";
                    ctime = "Child Time: " + childTime.ToString() + " ns";
                    break;
                case Scale_Enum.US:
                    duration = "Duration: " + local.ProfilingEvent.Details.Duration.Value / 1000 + " us";
                    ctime = "Child Time: " + childTime / 1000 + " us";
                    break;
                case Scale_Enum.MS:
                    duration = "Duration: " + local.ProfilingEvent.Details.Duration.Value / 1000 / 1000 + " ms";
                    ctime = "Child Time: " + childTime / 1000 / 1000 + " ms";
                    break;
            }
            //string duration = "Duration: " + local.ProfilingEvent.Details.Duration.Value.ToString() + " ns";
            //string ctime = "Child Time: " + " ns";
            string file = "File: " + local.ProfilingEvent.Details.File;
            string line = "Line: " + local.ProfilingEvent.Details.Line.ToString();
            ListViewItem item = new ListViewItem(new string[] { function });
            string stacktrace = "Stacktrace: \n";
            if (local.ProfilingEvent.Details.Stacktrace != null)
            {
                foreach (var stack in local.ProfilingEvent.Details.Stacktrace)
                {
                    stacktrace += stack.Symbol.Name + "\n";
                    //listViewDetails.Items.Add(new ListViewItem(new string[] { stack.Symbol.Name }));
                }
            }
            ElemnttDetails.Text = function + "\n" + duration + "\n" + ctime+"\n"+ file + "\n" + line + "\n" + stacktrace;


        }
        public void SetProgressbatr(float value)
        {

            toolStripProgressBar1.Value = (int)value;
        }
        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void ElemnttDetails_TextChanged(object sender, EventArgs e)
        {

        }

        private void LoadProfLog_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.InitialDirectory = "C:\\"; // Set default directory
                openFileDialog.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
                openFileDialog.FilterIndex = 1;
                openFileDialog.RestoreDirectory = true;

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    Globals.Logpath = openFileDialog.FileName;
                    MessageBox.Show("Selected file: " + Globals.Logpath, "File Opened", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
        }
        private void DrawNode(Graphics g, TimerTreeNode node, int x, int y)
        {
            g.DrawString(node.Text, Font, Brushes.Black, x, y);
            y += Font.Height;
            foreach (TimerTreeNode child in node.Nodes)
            {
                DrawNode(g, child, x + 10, y);
            }
        }
        float progress = 0;
        float progressStep = 0;

        private void treeViewProfiler_DrawNode(object sender, DrawTreeNodeEventArgs e)
        {
            if(progressStep == 0)
            {
                progressStep =100/ treeViewProfiler.Nodes.Count;
            }
            e.Graphics.FillRectangle(Brushes.White, e.Bounds); // Clear background
            e.Graphics.DrawRectangle(Pens.Black, new Rectangle(e.Bounds.X + (30 * e.Node.Level), e.Bounds.Y, 20, 20)); // Draw rectangle
            int i = e.Node.Text.Length;
            double dur = ((TimerTreeNode)e.Node).ProfilingEvent.Details.Duration.Value;

                    dur = dur ;

            switch (Currnet_Sacele)
            {
                case Scale_Enum.NS:
                    dur = dur;
                    break;
                case Scale_Enum.US:
                    dur = dur / 1000;
                    break;
                case Scale_Enum.MS:
                    dur = dur / 1000 / 1000;
                    break;
            }
            if (dur > int.MaxValue)
            {
                dur = (int)dur;
            }
            else
            {
                dur = Math.Round(dur);
            }
            if (dur > int.MaxValue/2)
            {
                dur = int.MaxValue/2;
            }
            Rectangle rectangle = new Rectangle(e.Bounds.X + 25 + (30 * e.Node.Level), e.Bounds.Y, 0 + (int)dur, 20);
            e.Graphics.FillRectangle(Brushes.Teal, rectangle); // Fill rectangle
            e.Graphics.DrawRectangle(Pens.Black, rectangle); // Draw rectangle

            e.Graphics.DrawString(e.Node.Text, treeViewProfiler.Font, Brushes.Black, e.Bounds.X + 25 + (30 * e.Node.Level), e.Bounds.Y);
            progress += progressStep;
            if(progress > 100)
            {
                progress = 100;
            }
            SetProgressbatr(progress);

        }

        private void Scale_MS_Click(object sender, EventArgs e)
        {
            Currnet_Sacele = Scale_Enum.MS;
            treeViewProfiler.Invalidate();
            ElemnttDetails.Invalidate();
        }

        private void Scale_US_Click(object sender, EventArgs e)
        {
            Currnet_Sacele = Scale_Enum.US;
            treeViewProfiler.Invalidate();

            ElemnttDetails.Invalidate();

        }

        private void Scale_NS_Click(object sender, EventArgs e)
        {
            Currnet_Sacele = Scale_Enum.NS;
            MessageBox.Show("setting scale to ns\n values larger than intmax/2 will be capped at intmax/2\nLarge values might break and become negative (this should only affect rendering)");
            treeViewProfiler.Invalidate();
            ElemnttDetails.Invalidate();


        }
    }
}

