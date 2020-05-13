<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.runBatchRenamer = New System.Windows.Forms.Button()
        Me.directoryBrowse = New System.Windows.Forms.Button()
        Me.directoryName = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.FolderBrowserDialog1 = New System.Windows.Forms.FolderBrowserDialog()
        Me.namingFormat = New System.Windows.Forms.TextBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Panel1 = New System.Windows.Forms.Panel()
        Me.bitrate = New System.Windows.Forms.Button()
        Me.rating = New System.Windows.Forms.Button()
        Me.modified = New System.Windows.Forms.Button()
        Me.created = New System.Windows.Forms.Button()
        Me.size = New System.Windows.Forms.Button()
        Me.album = New System.Windows.Forms.Button()
        Me.duration = New System.Windows.Forms.Button()
        Me.year = New System.Windows.Forms.Button()
        Me.track = New System.Windows.Forms.Button()
        Me.genre = New System.Windows.Forms.Button()
        Me.artist = New System.Windows.Forms.Button()
        Me.title = New System.Windows.Forms.Button()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Help = New System.Windows.Forms.Button()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Panel1.SuspendLayout()
        Me.SuspendLayout()
        '
        'runBatchRenamer
        '
        Me.runBatchRenamer.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.runBatchRenamer.Location = New System.Drawing.Point(24, 218)
        Me.runBatchRenamer.Name = "runBatchRenamer"
        Me.runBatchRenamer.Size = New System.Drawing.Size(159, 23)
        Me.runBatchRenamer.TabIndex = 0
        Me.runBatchRenamer.Text = "Let's name some files!"
        Me.runBatchRenamer.UseVisualStyleBackColor = True
        '
        'directoryBrowse
        '
        Me.directoryBrowse.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.directoryBrowse.Location = New System.Drawing.Point(468, 12)
        Me.directoryBrowse.Name = "directoryBrowse"
        Me.directoryBrowse.Size = New System.Drawing.Size(75, 23)
        Me.directoryBrowse.TabIndex = 1
        Me.directoryBrowse.Text = "Browse"
        Me.directoryBrowse.UseVisualStyleBackColor = True
        '
        'directoryName
        '
        Me.directoryName.Location = New System.Drawing.Point(102, 14)
        Me.directoryName.Name = "directoryName"
        Me.directoryName.ReadOnly = True
        Me.directoryName.Size = New System.Drawing.Size(360, 20)
        Me.directoryName.TabIndex = 2
        Me.directoryName.Text = "No directory selected"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(21, 17)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(49, 13)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "Directory"
        '
        'namingFormat
        '
        Me.namingFormat.Location = New System.Drawing.Point(102, 166)
        Me.namingFormat.Name = "namingFormat"
        Me.namingFormat.Size = New System.Drawing.Size(441, 20)
        Me.namingFormat.TabIndex = 4
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(21, 169)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(75, 13)
        Me.Label2.TabIndex = 5
        Me.Label2.Text = "Naming format"
        '
        'Panel1
        '
        Me.Panel1.Controls.Add(Me.bitrate)
        Me.Panel1.Controls.Add(Me.rating)
        Me.Panel1.Controls.Add(Me.modified)
        Me.Panel1.Controls.Add(Me.created)
        Me.Panel1.Controls.Add(Me.size)
        Me.Panel1.Controls.Add(Me.album)
        Me.Panel1.Controls.Add(Me.duration)
        Me.Panel1.Controls.Add(Me.year)
        Me.Panel1.Controls.Add(Me.track)
        Me.Panel1.Controls.Add(Me.genre)
        Me.Panel1.Controls.Add(Me.artist)
        Me.Panel1.Controls.Add(Me.title)
        Me.Panel1.Location = New System.Drawing.Point(24, 82)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(491, 59)
        Me.Panel1.TabIndex = 6
        '
        'bitrate
        '
        Me.bitrate.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.bitrate.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.bitrate.Location = New System.Drawing.Point(408, 32)
        Me.bitrate.Name = "bitrate"
        Me.bitrate.Size = New System.Drawing.Size(75, 23)
        Me.bitrate.TabIndex = 11
        Me.bitrate.Text = "Bitrate"
        Me.bitrate.UseVisualStyleBackColor = False
        '
        'rating
        '
        Me.rating.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.rating.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.rating.Location = New System.Drawing.Point(246, 32)
        Me.rating.Name = "rating"
        Me.rating.Size = New System.Drawing.Size(75, 23)
        Me.rating.TabIndex = 10
        Me.rating.Text = "Rating"
        Me.rating.UseVisualStyleBackColor = False
        '
        'modified
        '
        Me.modified.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.modified.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.modified.Location = New System.Drawing.Point(327, 32)
        Me.modified.Name = "modified"
        Me.modified.Size = New System.Drawing.Size(75, 23)
        Me.modified.TabIndex = 9
        Me.modified.Text = "Modified"
        Me.modified.UseVisualStyleBackColor = False
        '
        'created
        '
        Me.created.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.created.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.created.Location = New System.Drawing.Point(327, 4)
        Me.created.Name = "created"
        Me.created.Size = New System.Drawing.Size(75, 23)
        Me.created.TabIndex = 8
        Me.created.Text = "Created"
        Me.created.UseVisualStyleBackColor = False
        '
        'size
        '
        Me.size.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.size.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.size.Location = New System.Drawing.Point(408, 4)
        Me.size.Name = "size"
        Me.size.Size = New System.Drawing.Size(75, 23)
        Me.size.TabIndex = 7
        Me.size.Text = "Size"
        Me.size.UseVisualStyleBackColor = False
        '
        'album
        '
        Me.album.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.album.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.album.Location = New System.Drawing.Point(84, 32)
        Me.album.Name = "album"
        Me.album.Size = New System.Drawing.Size(75, 23)
        Me.album.TabIndex = 6
        Me.album.Text = "Album"
        Me.album.UseVisualStyleBackColor = False
        '
        'duration
        '
        Me.duration.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.duration.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.duration.Location = New System.Drawing.Point(165, 33)
        Me.duration.Name = "duration"
        Me.duration.Size = New System.Drawing.Size(75, 23)
        Me.duration.TabIndex = 5
        Me.duration.Text = "Duration"
        Me.duration.UseVisualStyleBackColor = False
        '
        'year
        '
        Me.year.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.year.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.year.Location = New System.Drawing.Point(165, 4)
        Me.year.Name = "year"
        Me.year.Size = New System.Drawing.Size(75, 23)
        Me.year.TabIndex = 4
        Me.year.Text = "Year"
        Me.year.UseVisualStyleBackColor = False
        '
        'track
        '
        Me.track.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.track.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.track.Location = New System.Drawing.Point(246, 4)
        Me.track.Name = "track"
        Me.track.Size = New System.Drawing.Size(75, 23)
        Me.track.TabIndex = 3
        Me.track.Text = "Track No."
        Me.track.UseVisualStyleBackColor = False
        '
        'genre
        '
        Me.genre.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.genre.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.genre.Location = New System.Drawing.Point(84, 4)
        Me.genre.Name = "genre"
        Me.genre.Size = New System.Drawing.Size(75, 23)
        Me.genre.TabIndex = 2
        Me.genre.Text = "Genre"
        Me.genre.UseVisualStyleBackColor = False
        '
        'artist
        '
        Me.artist.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.artist.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.artist.Location = New System.Drawing.Point(3, 32)
        Me.artist.Name = "artist"
        Me.artist.Size = New System.Drawing.Size(75, 23)
        Me.artist.TabIndex = 1
        Me.artist.Text = "Artist"
        Me.artist.UseVisualStyleBackColor = False
        '
        'title
        '
        Me.title.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.title.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.title.Location = New System.Drawing.Point(3, 4)
        Me.title.Name = "title"
        Me.title.Size = New System.Drawing.Size(75, 23)
        Me.title.TabIndex = 0
        Me.title.Text = "Title"
        Me.title.UseVisualStyleBackColor = False
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(21, 65)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(107, 13)
        Me.Label3.TabIndex = 7
        Me.Label3.Text = "Naming format helper"
        '
        'Help
        '
        Me.Help.Location = New System.Drawing.Point(513, 117)
        Me.Help.Name = "Help"
        Me.Help.Size = New System.Drawing.Size(18, 21)
        Me.Help.TabIndex = 8
        Me.Help.Text = "?"
        Me.Help.UseVisualStyleBackColor = True
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(352, 228)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(191, 13)
        Me.Label4.TabIndex = 9
        Me.Label4.Text = "Made by MiracleTonicPear // E Parton"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.SystemColors.Control
        Me.ClientSize = New System.Drawing.Size(551, 261)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Help)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.namingFormat)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.directoryName)
        Me.Controls.Add(Me.directoryBrowse)
        Me.Controls.Add(Me.runBatchRenamer)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "Form1"
        Me.Text = "MTP MP3 Renamer"
        Me.Panel1.ResumeLayout(False)
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents runBatchRenamer As Button
    Friend WithEvents directoryBrowse As Button
    Friend WithEvents directoryName As TextBox
    Friend WithEvents Label1 As Label
    Friend WithEvents FolderBrowserDialog1 As FolderBrowserDialog
    Friend WithEvents namingFormat As TextBox
    Friend WithEvents Label2 As Label
    Friend WithEvents Panel1 As Panel
    Friend WithEvents Label3 As Label
    Friend WithEvents bitrate As Button
    Friend WithEvents rating As Button
    Friend WithEvents modified As Button
    Friend WithEvents created As Button
    Friend WithEvents size As Button
    Friend WithEvents album As Button
    Friend WithEvents duration As Button
    Friend WithEvents year As Button
    Friend WithEvents track As Button
    Friend WithEvents genre As Button
    Friend WithEvents artist As Button
    Friend WithEvents title As Button
    Friend WithEvents Help As Button
    Friend WithEvents Label4 As Label
End Class
