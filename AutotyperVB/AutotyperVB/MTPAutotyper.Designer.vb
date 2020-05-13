<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class MTPAutotyper
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
        Me.saveButton = New System.Windows.Forms.Button()
        Me.triggerText = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.typeText = New System.Windows.Forms.TextBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'saveButton
        '
        Me.saveButton.Anchor = CType(((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.saveButton.Location = New System.Drawing.Point(12, 241)
        Me.saveButton.Name = "saveButton"
        Me.saveButton.Size = New System.Drawing.Size(414, 46)
        Me.saveButton.TabIndex = 0
        Me.saveButton.Text = "Save settings"
        Me.saveButton.UseVisualStyleBackColor = True
        '
        'triggerText
        '
        Me.triggerText.Location = New System.Drawing.Point(83, 15)
        Me.triggerText.Name = "triggerText"
        Me.triggerText.Size = New System.Drawing.Size(52, 20)
        Me.triggerText.TabIndex = 1
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(9, 15)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(40, 13)
        Me.Label1.TabIndex = 2
        Me.Label1.Text = "Trigger"
        '
        'typeText
        '
        Me.typeText.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
            Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.typeText.Location = New System.Drawing.Point(83, 38)
        Me.typeText.Multiline = True
        Me.typeText.Name = "typeText"
        Me.typeText.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.typeText.Size = New System.Drawing.Size(343, 197)
        Me.typeText.TabIndex = 3
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(9, 38)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(63, 13)
        Me.Label2.TabIndex = 4
        Me.Label2.Text = "Text to type"
        '
        'MTPAutotyper
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(446, 299)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.typeText)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.triggerText)
        Me.Controls.Add(Me.saveButton)
        Me.KeyPreview = True
        Me.Name = "MTPAutotyper"
        Me.Text = "MTP AutoTyper"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents saveButton As Button
    Friend WithEvents triggerText As TextBox
    Friend WithEvents Label1 As Label
    Friend WithEvents typeText As TextBox
    Friend WithEvents Label2 As Label
End Class
