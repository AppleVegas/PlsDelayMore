#pragma once
#include "plsdelay.h"
#include "pch.h"
#include <msclr/marshal.h>

namespace PlsDelayMore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

		}

	protected:

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ enable_upd_button;
	private: System::Windows::Forms::Button^ delay_upd_button;
	private: System::Windows::Forms::PictureBox^ app_image;
	protected: System::Windows::Forms::DateTimePicker^ datePick;
	private:

	private: System::Windows::Forms::Button^ longdelay_upd_button;
	private: System::Windows::Forms::Label^ info_text;
	private: System::Windows::Forms::Label^ label1;


	protected:


	protected:


	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->enable_upd_button = (gcnew System::Windows::Forms::Button());
			this->delay_upd_button = (gcnew System::Windows::Forms::Button());
			this->app_image = (gcnew System::Windows::Forms::PictureBox());
			this->datePick = (gcnew System::Windows::Forms::DateTimePicker());
			this->longdelay_upd_button = (gcnew System::Windows::Forms::Button());
			this->info_text = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->app_image))->BeginInit();
			this->SuspendLayout();
			// 
			// enable_upd_button
			// 
			this->enable_upd_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->enable_upd_button->Location = System::Drawing::Point(4, 109);
			this->enable_upd_button->Name = L"enable_upd_button";
			this->enable_upd_button->Size = System::Drawing::Size(96, 48);
			this->enable_upd_button->TabIndex = 0;
			this->enable_upd_button->Tag = L"What";
			this->enable_upd_button->Text = L"Resume updates";
			this->enable_upd_button->UseVisualStyleBackColor = false;
			this->enable_upd_button->Click += gcnew System::EventHandler(this, &Form1::enable_Click);
			// 
			// delay_upd_button
			// 
			this->delay_upd_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->delay_upd_button->Location = System::Drawing::Point(106, 109);
			this->delay_upd_button->Name = L"delay_upd_button";
			this->delay_upd_button->Size = System::Drawing::Size(172, 48);
			this->delay_upd_button->TabIndex = 1;
			this->delay_upd_button->Tag = L"What";
			this->delay_upd_button->Text = L"Delay updates";
			this->delay_upd_button->UseVisualStyleBackColor = false;
			this->delay_upd_button->Click += gcnew System::EventHandler(this, &Form1::delay_Click);
			// 
			// app_image
			// 
			this->app_image->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"app_image.ErrorImage")));
			this->app_image->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"app_image.Image")));
			this->app_image->ImageLocation = L"";
			this->app_image->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"app_image.InitialImage")));
			this->app_image->Location = System::Drawing::Point(4, 7);
			this->app_image->Name = L"app_image";
			this->app_image->Size = System::Drawing::Size(96, 96);
			this->app_image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->app_image->TabIndex = 2;
			this->app_image->TabStop = false;
			// 
			// datePick
			// 
			this->datePick->Location = System::Drawing::Point(106, 83);
			this->datePick->Name = L"datePick";
			this->datePick->Size = System::Drawing::Size(274, 20);
			this->datePick->TabIndex = 3;
			// 
			// longdelay_upd_button
			// 
			this->longdelay_upd_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->longdelay_upd_button->Location = System::Drawing::Point(284, 109);
			this->longdelay_upd_button->Name = L"longdelay_upd_button";
			this->longdelay_upd_button->Size = System::Drawing::Size(96, 48);
			this->longdelay_upd_button->TabIndex = 4;
			this->longdelay_upd_button->Tag = L"What";
			this->longdelay_upd_button->Text = L"Delay for 1 year";
			this->longdelay_upd_button->UseVisualStyleBackColor = false;
			this->longdelay_upd_button->Click += gcnew System::EventHandler(this, &Form1::year_delay_Click);
			// 
			// info_text
			// 
			this->info_text->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->info_text->Location = System::Drawing::Point(107, 7);
			this->info_text->Name = L"info_text";
			this->info_text->Size = System::Drawing::Size(273, 54);
			this->info_text->TabIndex = 5;
			this->info_text->Text = L"Please, choose the date when updates will be resumed. When chosen, push \"Delay Up"
				L"dates\" button. \nYou can also just delay updates for 1 year from now, for that pu"
				L"sh \"Delay for 1 year\" button.";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(106, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Delay until:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 161);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->info_text);
			this->Controls->Add(this->longdelay_upd_button);
			this->Controls->Add(this->datePick);
			this->Controls->Add(this->app_image);
			this->Controls->Add(this->delay_upd_button);
			this->Controls->Add(this->enable_upd_button);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(400, 200);
			this->MinimumSize = System::Drawing::Size(400, 200);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Please, delay more...";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->app_image))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void delay_Click(System::Object^ sender, System::EventArgs^ e) {
		System::DateTime dated = this->datePick->Value;
		System::String^ formatted = dated.ToString("yyyy-MM-ddTHH:mm:ssZ");
		msclr::interop::marshal_context mc;
		const char* pausedate = mc.marshal_as<const char*>(formatted);

		if (DelayUntil(pausedate))
			MessageBoxW(NULL, L"Updates successfully delayed!", L"Success", MB_OK | MB_ICONASTERISK);
		else
			MessageBoxW(NULL, L"Delaying updates failed!", L"Failed", MB_OK | MB_ICONERROR);
	}

	private: System::Void year_delay_Click(System::Object^ sender, System::EventArgs^ e) {
		if (DelayForYear())
			MessageBoxW(NULL, L"Updates successfully delayed!", L"Success", MB_OK | MB_ICONASTERISK);
		else
			MessageBoxW(NULL, L"Delaying updates failed!", L"Failed", MB_OK | MB_ICONERROR);
	}
	private: System::Void enable_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ResumeUpdates())
			MessageBoxW(NULL, L"Updates successfully resumed!", L"Success", MB_OK | MB_ICONASTERISK);
		else
			MessageBoxW(NULL, L"Resuming updates failed!", L"Failed", MB_OK | MB_ICONERROR);
	}

};
}
