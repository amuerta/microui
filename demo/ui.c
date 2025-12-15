mu_slider_impl(mu_slider_u8, unsigned char);



#define fmt_toggle(T) (T) ? "on" : "off"


void page_one(mu_Context* ui, int font_size) {
    static bool     toggle1;
    static Color    color1;
    mu_row_ruler(ui, font_size, mu_percent(.50), mu_percent(.50));
    mu_label(ui, "Button 1");
    mu_button(ui,"Im a button");

    mu_label(ui, "Toggle 1");
    if(mu_button(ui, fmt_toggle(toggle1), "sel_toggle1")) 
        toggle1 = !toggle1;


    mu_row_ruler(ui, font_size, mu_percent_left(.90),mu_pixels(45),mu_pixels(45),mu_pixels(45));
    mu_label(ui, "Color");


    static bool color_1_slider;
    static float flt; 
    mu_slider_u8(ui, &(color1.r), 0, 255);
    mu_slider_u8(ui, &(color1.g), 0, 255);
    mu_slider_u8(ui, &(color1.b), 0, 255);


    mu_row_ruler(ui, font_size, mu_expand());

    // drop down has to be right after the elemen you want a drop down to appear
    if(mu_button(ui, "Drop down", "sel_drop1")) 
        mu_toggle_dropdown(ui, "drop1", 100);
    if(mu_begin_dropdown(ui, "drop1")) {
        mu_row(ui, font_size, -1);
        int bts[] = {
            mu_button(ui, "drop option 1"),
            mu_button(ui, "drop option 2"),
            mu_button(ui, "drop option 3"),
            mu_button(ui, "drop option 4"),
            mu_button(ui, "drop option 5")
        };

        mu_end_dropdown(ui);
        for(int i = 0; i < 5; i++) if(bts[i]) 
            mu_toggle_dropdown(ui, "drop1", 0);
    }

    mu_row_ruler(ui, font_size, mu_expand());
    if (mu_header(ui, "Header 1")) {
        mu_layout_height(ui, 100);
        mu_begin_panel(ui, "panel1");

        mu_end_panel(ui);
    }

}




void ui_logic(Context* ctx) {
    enum { PAGE_NULL, PAGE_FIRST, PAGE_SECOND };
    mu_Context* ui = &ctx->ui;
    mu_begin(ui);
    static int page = PAGE_FIRST;
    int font_size = MU_RL_FONT_SIZE + 8;

    if(mu_begin_window(ui, "Controls", mu_rect(100,100,300,400))) {
        mu_row(ui, font_size,  120, 120);

        mu_row_ruler(ui, font_size, mu_percent(.50), mu_percent(.50));
        page = mu_button(ui, "Page 1") ? PAGE_FIRST     :page;
        page = mu_button(ui, "Page 2") ? PAGE_SECOND    :page;

        switch (page) {
            case PAGE_FIRST:
                mu_row(ui, mu_height_left(ui), -1);
                mu_begin_panel(ui, "page_first");
                mu_row(ui, font_size,  100, 100);
                page_one(ui, font_size); 
                mu_end_panel(ui);
                break;
            
            case PAGE_SECOND: break;

            default: break;
        }


        mu_end_window(ui);
    }
    mu_end(ui);
}
