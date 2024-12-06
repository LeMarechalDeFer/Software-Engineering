-- vue entre newsletter et user

-- CREATE OR REPLACE VIEW user_newsletter_subscriptions AS
-- SELECT 
--     n.id AS newsletter_id,
--     u.id AS user_id,
--     n.email,
--     u.created_at AS user_created_at,
--     n.created_at AS subscription_date
-- FROM newsletters n
-- LEFT JOIN users u ON n.email = u.email;


-- -- recup les traductions
-- SELECT JSON_OBJECT(
--            'lang_code' VALUE lang_code,
--            'key' VALUE key,
--            'translation' VALUE translations
--        ) AS json_data
-- FROM translations;


-- SELECT s.id, t.translation AS name, sp.start_date, sp.end_date
-- FROM seasons s
-- JOIN translations t
--   ON t.entity_name = 'seasons' AND t.entity_id = s.id AND t.lang_code = 'fr' AND t.field_name = 'name'
-- JOIN season_periods sp
--   ON sp.season_id = s.id;



-- CREATE OR REPLACE VIEW view_seasons_translations AS
-- SELECT 
--     s.id,
--     s.default_name AS default_name,
--     t.lang_code,
--     t.translation AS name
-- FROM seasons s
-- LEFT JOIN translations t
--   ON t.entity_name = 'seasons' AND t.entity_id = s.id AND t.field_name = 'name';
